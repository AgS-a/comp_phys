#! /bin/bash

cd ./MD_thermostat/good_run
./q3 > time.log

cd ../../MD_neig-list/1200part
./q4 > time.log

cd ../2400part
./q4 > time.log

cd ../3600part
./q4 > time.log
