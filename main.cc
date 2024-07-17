#include <iostream>
#include <fstream>
#include <sstream>
#include <cxxopts.hpp>
#include <crow/crow_all.h>

// int main(){
//     std::cout << "hello" << std::endl;
//     return 0;
// } 

// int main(int argc, char **argv){

//     cxxopts::Options options("hello");
//     options.add_options("arguments")("h,help", "Print usage");

//     auto result = options.parse(argc, argv);

//     if (result.count("help"))
//     {
//         std::cout << options.help() << '\n';
//     }

//     std::cout<< "hello";


//     return 0;
// } 



// int main() {
//   crow::SimpleApp app;

//   CROW_ROUTE(app, "/")
//   ([]() {
//     return "Hello, world!";
//   });

//   app.port(8080).multithreaded().run();
// }


// int main()
// {
//     crow::SimpleApp app;

//     CROW_ROUTE(app, "/hello")
//     ([](){
//         crow::json::wvalue response;
//         response["message"] = "Hello, world!";
//         response["message2"] = "Hello, World.. Again!";
//         return response;
//     });

//     app.port(8080).multithreaded().run();
// }


// int main()
// {
//     crow::SimpleApp app;

// CROW_ROUTE(app,"/hello/<int>")
// ([](int count){
//     if (count > 100)
//         return crow::response(400);
//     std::ostringstream os;
//     os << count << " bottles of beer!";
//     return crow::response(os.str());
// });

//     app.port(8080).multithreaded().run();
// }

////////////////////////////////////////////////////
// 👇 great post request here are the 

// json payload : 
//{
//     "a":"5",
//     "b":"6"
// }

// int main()
// {
//     crow::SimpleApp app;

// CROW_ROUTE(app, "/add_json")
// .methods("POST"_method)
// ([](const crow::request& req){
//     auto x = crow::json::load(req.body);
//     if (!x)
//         return crow::response(crow::response(400)); // crow::status::BAD_REQUEST is bullshit
//     int sum = x["a"].i()+x["b"].i();
//     std::ostringstream os;
//     os << sum;
//     return crow::response{os.str()};
// });

//     app.port(8080).multithreaded().run();
// }

///////////////////////////////////////////////////////////

// int main()
// {
//     crow::SimpleApp app;

// CROW_ROUTE(app, "/add_json")
// .methods("POST"_method)
// ([](const crow::request& req){
//     auto x = crow::json::load(req.body);
//     if (!x)
//         return crow::response(crow::response(400)); // crow::status::BAD_REQUEST is bullshit
//   //   int sum = x["image"].i();  // POST http://localhost:8080/add_json {"image": "12344980"}
//     std::string sum = x["image"].s();
//     std::ostringstream os;
//     os << sum;
//     return crow::response{os.str()};
// });

//     app.port(8080).multithreaded().run();
// }
///////////////////////////////////////////////////////////////////////////////////////////
// now this will write it in a json file

// void save_json_to_file(const std::string& json_data, const std::string& filename) {
//     std::ofstream file(filename);
//     if (file.is_open()) {
//         file << json_data;
//         file.close();
//     }
// }

// int main() {
//     crow::SimpleApp app;

//     int requestCount = 1;

//     CROW_ROUTE(app, "/add_json")
//     .methods("POST"_method)
//     ([&requestCount](const crow::request& req)  {
//         auto x = crow::json::load(req.body);
//         if (!x)
//             return crow::response(400); // Bad Request

//         std::string jsonStr = x["image"].s();
//         // std::string jsonStr = crow::json::dump(x);

//         std::ostringstream os;
//          os << jsonStr;

//         std::ostringstream filename;
//         filename << "send" << requestCount << ".json";

//         save_json_to_file(jsonStr, filename.str());

//         requestCount++;

//         return crow::response{os.str()};
//     });

//     app.port(8080).multithreaded().run();
// }

///////////////////////////////////////////////////////////////////////////////////////////////
// now it print the whole request 

void save_json_to_file(const std::string& json_data, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << json_data;
        file.close();
    }
}

int main() {
    crow::SimpleApp app;

    int requestCount = 1;

    CROW_ROUTE(app, "/add_json")
    .methods("POST"_method)
    ([&requestCount](const crow::request& req)  {
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400); // Bad Request

        // std::string jsonStr = x["image"].s();
        std::string jsonStr = crow::json::dump(x);

        std::ostringstream os;
         os << jsonStr;

        std::ostringstream filename;
        filename << "send" << requestCount << ".json";

        save_json_to_file(jsonStr, filename.str());

        requestCount++;

        return crow::response{os.str()};
    });

    app.port(8080).multithreaded().run();
}