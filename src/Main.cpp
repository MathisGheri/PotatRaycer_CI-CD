/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Main
*/

#include "include.hpp"
#include "Core.hpp"
#include "SingletonLogger.hpp"
#include "Exception.hpp"
#include "FileWatcherSingleton.hpp"
#include "Mesh.hpp"
#include "Triangle.hpp"

bool loadOBJ(const std::string& filename, Mesh& mesh)
{
    std::vector<Vec3> vertices;
    std::vector<Triangle> triangles;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;
        if (prefix == "v") {
            Vec3 vertex;
            iss >> vertex.e[0] >> vertex.e[1] >> vertex.e[2];
            vertices.push_back(vertex);
        } else if (prefix == "f") {
            int idx[3];
            iss >> idx[0] >> idx[1] >> idx[2];  // Simplified for triangles
            Triangle triangle(vertices[idx[0] - 1], vertices[idx[1] - 1], vertices[idx[2] - 1]);
            triangles.push_back(triangle);
        }
    }

    mesh = Mesh(triangles);  // Assuming Mesh has a constructor that accepts a std::vector<Triangle>
    return true;
}

int main(int argc, char **argv)
{
    Mesh myMesh;
    if (loadOBJ(argv[1], myMesh)) {
        std::cout << "Loaded OBJ model with " << myMesh.getTriangles().size() << " triangles." << std::endl;
    } else {
        std::cerr << "Failed to load OBJ model." << std::endl;
    }
    exit(0);
    //try // expect
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-potat") == 0)) { //changer pour du cpp
        printf("./Raytracer --help\nUSAGE: ./Raytracer <SCENE_FILE>\nSCENE_FILE: scene configuration\n");
        exit(0);
    } else if (argc > 2) {
        exit(84);
    }
    /**********************/
    Logger *logger = LoggerSingleton::getInstance();
    FileWatcher *watcher = FileWatcherSingleton::getInstance();
    watcher->setFileToWatch(argv[1]);
    try {
        logger->log(INFO, "Application started.");
        const std::string &file = argv[1];
        Core core;
        core.assembleScene(file);
        logger->log(INFO, "Initialisation ended.");
        core.generatePPM();
        //Parser
        //SceneBuilder
        //Scene
        //Calcul
        //Rendu
    } catch (const Exception& e) {
        std::cout << "Exception captured: " << e.what() << ". With Level: ";
        switch (e.getLevel()) {
            case Level::LOW:
                std::cout << "low";
                break;
            case Level::MIDDLE:
                std::cout << "middle";
                break;
            case Level::HIGH:
                std::cout << "HIGH";
                break;
        }
        std::cout << std::endl;
        //free destroy delete etc..
        return 84;
    }
    logger->log(INFO, "Application Stopped.\n");
    return 0;
}
