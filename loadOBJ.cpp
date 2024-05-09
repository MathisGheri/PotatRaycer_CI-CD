/*
** EPITECH PROJECT, 2023
** PotatRaycer_CI-CD
** File description:
** loadOBJ.cpp
*/

bool loadOBJ(const std::string& filename, Mesh& mesh) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;
        if (prefix == "v") {
            Vertex v;
            iss >> v.x >> v.y >> v.z;
            mesh.vertices.push_back(v);
        } else if (prefix == "vt") {
            TextureCoord t;
            iss >> t.u >> t.v;
            mesh.textures.push_back(t);
        } else if (prefix == "vn") {
            Normal n;
            iss >> n.nx >> n.ny >> n.nz;
            mesh.normals.push_back(n);
        } else if (prefix == "f") {
            Face f;
            std::string vertex;
            while (iss >> vertex) {
                std::istringstream vertexStream(vertex);
                std::string index;
                int i = 0;
                while (getline(vertexStream, index, '/')) {
                    if (!index.empty()) {
                        int idx = std::stoi(index) - 1;
                        if (i == 0) f.vertex_indices.push_back(idx);
                        else if (i == 1) f.texture_indices.push_back(idx);
                        else if (i == 2) f.normal_indices.push_back(idx);
                    }
                    i++;
                }
            }
            mesh.faces.push_back(f);
        }
    }
    file.close();
    return true;
}
