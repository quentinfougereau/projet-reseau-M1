ip link set tun0 up
ip a add 172.16.2.1/28 dev tun0
ip route add 172.16.2.176/28 via 172.16.2.1 dev tun0
