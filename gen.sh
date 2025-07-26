#!/bin/bash

./build/tpcc_generate_data tpcc_csv/
wc -l tpcc_csv/*.csv

CSV_DIR=tpcc_csv
NOHEADER_CSV_DIR=tpcc_csv_no_header
mkdir -p $NOHEADER_CSV_DIR
for file in $(ls $CSV_DIR | grep ".csv"); do
    tail -n+2 $CSV_DIR/$file > $NOHEADER_CSV_DIR/$file
done;
wc -l tpcc_csv_no_header/*.csv

# head -2 tpcc_csv_no_header/*.csv
