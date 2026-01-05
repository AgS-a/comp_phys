
#! /bin/bash

### Script to login to a computer. ###

SUBNET="192.168.10"

nofloop=0
while [ $nofloop -le 1000 ]  
do
    i=$((16 + RANDOM% 112))

    IP_ADDRESS="${SUBNET}.${i}"

    ping -c 1 -W 0.5 ${IP_ADDRESS} &> /dev/null

    if [ $? -eq 0 ]; then
        break
    fi

    ((nofloop++))
done

USERNAME="abhaygnanaskandan.s"

konsole -e "ssh -o StrictHostKeyChecking=no -L 51234:localhost:51234 ${USERNAME}@${IP_ADDRESS}" &
