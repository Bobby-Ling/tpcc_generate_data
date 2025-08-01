#!/bin/bash

WAREHOUSE_NUM=$1
if [ -z "$WAREHOUSE_NUM" ]; then
    WAREHOUSE_NUM=50
fi

# CONFIG_NUM_WARE=2 ./build/tpcc_generate_data tpcc_sql/

# head -1000 tpcc_sql/*.sql | grep -v "==>" > demo.sql

# 50个warehouse
CONFIG_NUM_WARE=$WAREHOUSE_NUM ./build/tpcc_generate_data tpcc_csv/
wc -l tpcc_csv/*.csv

CSV_DIR=tpcc_csv
NOHEADER_CSV_DIR=tpcc_csv_no_header
mkdir -p $NOHEADER_CSV_DIR
for file in $(ls $CSV_DIR | grep ".csv"); do
    tail -n+2 $CSV_DIR/$file > $NOHEADER_CSV_DIR/$file
done;

head -2 tpcc_csv/*.csv

wc -l tpcc_csv_no_header/*.csv


# ./gen.sh 2
# CONFIG_NUM_WARE = 2
#     60001 tpcc_csv/customer.csv
#        21 tpcc_csv/district.csv
#     60001 tpcc_csv/history.csv
#    100001 tpcc_csv/item.csv
#     18001 tpcc_csv/new_orders.csv
#    600001 tpcc_csv/order_line.csv
#     60001 tpcc_csv/orders.csv
#    200001 tpcc_csv/stock.csv
#         3 tpcc_csv/warehouse.csv
#   1098031 总计
#     60000 tpcc_csv_no_header/customer.csv
#        20 tpcc_csv_no_header/district.csv
#     60000 tpcc_csv_no_header/history.csv
#    100000 tpcc_csv_no_header/item.csv
#     18000 tpcc_csv_no_header/new_orders.csv
#    600000 tpcc_csv_no_header/order_line.csv
#     60000 tpcc_csv_no_header/orders.csv
#    200000 tpcc_csv_no_header/stock.csv
#         2 tpcc_csv_no_header/warehouse.csv
#   1098022 总计
