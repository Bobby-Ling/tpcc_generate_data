#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <mutex>
#include <string>
#include <string_view>
#include "log.h"

namespace CONFIG {

inline static const int TABLE_NUM = 9;                  // 共9张表
inline static int NUM_WARE = 50;                        // 仓库数量
inline static const int STOCK_PER_WARE = 100000;        // 每个仓库有十万种商品的库存数据
inline static const int DISTRICT_PER_WARE = 10;         // 每个仓库为10个地区提供服务
inline static const int CUSTOMER_PER_DISTRICT = 3000;   // 每个地区有3000个用户
inline static const int HISTORY_PER_CUSTOMER = 1;       // 每个用户有一条交易历史
inline static const int ORDER_PER_DISTRICT = 3000;      // 每个地区有3000个订单
inline static const int FIRST_UNPROCESSED_O_ID = 2101;  // 第一个未处理的订单
inline static const int MAXITEMS = 100000;              // 有多少个item

template <typename T>
inline static void init_config(T &config, std::string_view config_name) {
    std::string_view config_name_sv = config_name.substr(config_name.find("::") + 2);
    std::string env_name = "CONFIG_" + std::string(config_name_sv.data());
    char *env = getenv(env_name.c_str());
    if (env) {
        config = static_cast<T>(std::stoi(env));
    }
    std::cout << fmt::format("{} = {}", env_name, config) << std::endl;
}

};

#define INIT_CONFIG(name)            \
    {                                               \
        constexpr std::string_view config_name = #name;               \
        CONFIG::init_config(name, config_name.data()); \
    }

inline void init_all_config() {
    INIT_CONFIG(CONFIG::NUM_WARE);
}


// #define TABLE_NUM 9                     // 共9张表
// #define NUM_WARE 50                      // 仓库数量
// #define STOCK_PER_WARE  100000          // 每个仓库有十万种商品的库存数据
// #define DISTRICT_PER_WARE 10            // 每个仓库为10个地区提供服务
// #define CUSTOMER_PER_DISTRICT 3000      // 每个地区有3000个用户
// #define HISTORY_PER_CUSTOMER 1          // 每个用户有一条交易历史
// #define ORDER_PER_DISTRICT 3000         // 每个地区有3000个订单
// #define FIRST_UNPROCESSED_O_ID 2101     // 第一个未处理的订单
// #define MAXITEMS 100000                 // 有多少个item

using namespace CONFIG;

inline static std::vector<std::vector<int>> next_o_id(NUM_WARE+1, std::vector<int>(DISTRICT_PER_WARE+1));
inline static std::mutex next_o_id_mutex;

inline static std::vector<std::vector<int>> min_no_o_id(NUM_WARE+1, std::vector<int>(DISTRICT_PER_WARE+1));
inline static std::mutex min_no_o_id_mutex;


#endif