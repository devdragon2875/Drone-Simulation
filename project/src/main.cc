#include <iostream>
#include <map>
#include "web_app.h" 
#include <vector>
#include <string>
#include <memory>
#include "imageProcessor.h"
#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include "double_threshold_filter.h"
#include "composite_entity_factory.h"
#include "entity.h"
#include "entity_factory.h"
#include "robot.h"
#include "robot_factory.h"

int main(int argc, char**argv) {
    if (argc > 1) {
        int port = std::atoi(argv[1]);
        std::string webDir = std::string(argv[2]);
        WebServer<WebApp> server(port, webDir);
        while (true) {
            server.service();
        }
    }
    else {
        std::cout << "Usage: ./build/web-app 8081 web" << std::endl;
    }

    return 0;
}


