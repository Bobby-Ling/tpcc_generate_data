#include <netdb.h>
#include <netinet/in.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>
#include <termios.h>
#include <unistd.h>
#include <filesystem>

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <mutex>

#include "clock.h"
#include "config.h"
#include "table.h"
#include "log.h"

#define MAX_MEM_BUFFER_SIZE 8192
#define PORT_DEFAULT 8765
#define MAX_CLIENT_NUM 4    // 同时连接服务端的客户端数量
#define MAX_TXN_PER_CLIENT 1000 // 每个客户端执行的事务数量

#define load_data(table_name, file_name) table_name* table_name##_data = new table_name(); \
                              table_name##_data->generate_data_csv(file_name);

int main(int argc, char *argv[]) {
    init_logger();

    // Check input
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <output_path>" << std::endl;
        return -1;
    }

    std::string output_path = argv[1];

    if (!std::filesystem::exists(output_path)) {
        std::filesystem::create_directories(output_path);
    }

    SystemClock* clock = new SystemClock();
    RandomGenerator::init();

    // load data
    load_data(Warehouse, output_path + "/" + "warehouse.csv");
    load_data(District, output_path + "/" + "district.csv");
    load_data(Customer, output_path + "/" + "customer.csv");
    load_data(History, output_path + "/" + "history.csv");
    load_data(NewOrders, output_path + "/" + "new_orders.csv");
    load_data(Orders, output_path + "/" + "orders.csv");
    load_data(OrderLine, output_path + "/" + "order_line.csv");
    load_data(Item, output_path + "/" + "item.csv");
    load_data(Stock, output_path + "/" + "stock.csv");

    return 0;
}
