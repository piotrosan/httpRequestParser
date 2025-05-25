// // g++ main.cpp -Llibs -lpqxx -lpq
// using namespace std;
// using namespace pqxx;
//
// int main() {
//     pqxx::connection cx{"postgresql://postgres:example@localhost/example"};
//     string databaseName = cx.dbname();
//
//     pqxx::work tx{cx};
//
//     pqxx::result r{tx.exec("select id, text from test")};
//
//     for (auto row: r)
//         cout << "Record: "
//                 << row["id"].as<int>()
//                 << row["text"].as<string>()
//                 << endl;
//
//     tx.commit();
// }