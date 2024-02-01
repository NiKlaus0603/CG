#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct VertexInfo {
    float x, y, z;          // Coordinates
    float normal_x, normal_y, normal_z; // Normal
    float u = 0, v = 0;     // Texture coordinates, default to 0
};

struct Triangle {
    VertexInfo v1, v2, v3;
};

std::vector<std::string> split(const std::string &line, char delimiter) {
    std::istringstream stream(line);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

VertexInfo parseVertexLine(const std::string &line) {
    std::istringstream stream(line);
    VertexInfo vertex;
    stream >> vertex.x >> vertex.y >> vertex.z;
    return vertex;
}

// Additional parsing functions for normals, textures, and faces will go here

std::vector<Triangle> parseOBJ(const std::string &Audi_R8.obj) {
    std::ifstream file(Audi_R8.obj);
    std::string line;
    std::vector<VertexInfo> vertices, normals, textures;
    std::vector<Triangle> triangles;

    while (std::getline(file, line)) {
        if (line[0] == 'v') {
            if (line[1] == ' ') vertices.push_back(parseVertexLine(line.substr(2)));
            // Additional parsing for normals, textures, and faces will go here
        }
    }

    // Logic to construct triangles based on parsed data

    return triangles;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "USAGE: homework2_exe [Audi_R8.obj]" << std::endl;
        return 1;
    }
    std::string filename { argv[1] };
    auto triangles = parseOBJ(Audi_R8.obj);

    // Print triangles or other processing

    return 0;
}
