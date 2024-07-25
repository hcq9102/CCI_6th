//https://godbolt.org/z/v74r3jqez

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm> // For std::min

#define BLOCK_SIZE 1024 // Size of each data block

class DataBlock {
public:
    DataBlock() : data(BLOCK_SIZE, 0) {}

    std::vector<char>& getData() { return data; }
    const std::vector<char>& getData() const { return data; }

private:
    std::vector<char> data;
};

class Inode {
public:
    Inode() : name(""), size(0), creationTime(time(nullptr)), modificationTime(time(nullptr)) {}

    Inode(const std::string& name) 
        : name(name), size(0), creationTime(time(nullptr)), modificationTime(time(nullptr)) {}

    const std::string& getName() const { return name; }
    size_t getSize() const { return size; }
    void setSize(size_t newSize) { size = newSize; }
    const std::vector<size_t>& getDataBlocks() const { return dataBlocks; }
    void addDataBlock(size_t blockIndex) { dataBlocks.push_back(blockIndex); }
    void clearDataBlocks() { dataBlocks.clear(); }
    void updateModificationTime() { modificationTime = time(nullptr); }

private:
    std::string name;
    size_t size;
    std::vector<size_t> dataBlocks;
    time_t creationTime;
    time_t modificationTime;
};

class DirectoryEntry {
public:
    bool fileExists(const std::string& name) const {
        return files.find(name) != files.end();
    }

    void addFile(const std::string& name, size_t inodeIndex) {
        files[name] = inodeIndex;
    }

    size_t getFileInode(const std::string& name) const {
        return files.at(name);
    }

private:
    std::unordered_map<std::string, size_t> files;
};

class Superblock {
public:
    Superblock(size_t totalSize) : totalSize(totalSize), freeSpace(totalSize) {}

    size_t getTotalSize() const { return totalSize; }
    size_t getFreeSpace() const { return freeSpace; }
    void updateFreeSpace(size_t usedSpace) { freeSpace -= usedSpace; }

private:
    size_t totalSize;
    size_t freeSpace;
};

class FileSystem {
public:
    FileSystem(size_t size) : superblock(size) {
        blocks.resize(size / BLOCK_SIZE);
    }

    bool createFile(const std::string& name) {
        if (directory.fileExists(name)) {
            return false; // File already exists
        }
        size_t inodeIndex = inodes.size();
        inodes[inodeIndex] = Inode(name);
        directory.addFile(name, inodeIndex);
        return true;
    }

    bool writeFile(const std::string& name, const std::string& data) {
        if (!directory.fileExists(name)) {
            return false; // File does not exist
        }
        size_t inodeIndex = directory.getFileInode(name);
        Inode& inode = inodes[inodeIndex];

        inode.setSize(data.size());
        inode.clearDataBlocks();
        size_t remaining = data.size();
        size_t offset = 0;

        // Determine the number of data blocks needed
        while (remaining > 0) {
            size_t blockSize = std::min(static_cast<size_t>(BLOCK_SIZE), remaining);
            size_t blockIndex = inode.getDataBlocks().size();
            if (blockIndex >= blocks.size()) {
                return false; // Not enough space
            }

            DataBlock& block = blocks[blockIndex];
            std::copy(data.begin() + offset, data.begin() + offset + blockSize, block.getData().begin());
            inode.addDataBlock(blockIndex);
            offset += blockSize;
            remaining -= blockSize;
        }

        inode.updateModificationTime();
        superblock.updateFreeSpace(data.size());
        return true;
    }

    std::string readFile(const std::string& name) {
        if (!directory.fileExists(name)) {
            return ""; // File does not exist
        }
        size_t inodeIndex = directory.getFileInode(name);
        Inode& inode = inodes[inodeIndex];

        std::string data;
        for (size_t blockIndex : inode.getDataBlocks()) {
            const DataBlock& block = blocks[blockIndex];
            data.append(block.getData().begin(), block.getData().end());
        }
        return data.substr(0, inode.getSize()); // Return only the valid data
    }

private:
    Superblock superblock;
    DirectoryEntry directory;
    std::unordered_map<size_t, Inode> inodes;
    std::vector<DataBlock> blocks;
};

int main() {
    FileSystem fs(10240); // 10 MB file system

    fs.createFile("example.txt");
    fs.writeFile("example.txt", "Hello, World!");

    std::string content = fs.readFile("example.txt");
    std::cout << "Content of example.txt: " << content << std::endl;

    return 0;
}
