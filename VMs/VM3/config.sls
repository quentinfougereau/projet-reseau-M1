# Configuration eth1
# RAPPEL: eth0 est à vagrant, ne pas y toucher
## Désactivation de network-manager
ip route add default via 10.0.2.2:
  cmd:
    - run

dhclient eth0:
  cmd:
    - run
apt install -yy inetutils-inetd:
  cmd:
    - run

NetworkManager:
  service:
    - dead
    - enable: False

## Suppression de la passerelle par défaut
ip route del default:
  cmd:
    - run
## Configuration de VM3
eth1:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - ipaddr: 172.16.2.163
    - netmask: 28
eth2:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - ipaddr: 172.16.2.183
    - netmask: 28

## Configuration de la route vers LAN3 via VM3-6
routes:
  network.routes:
    - name: eth2
    - routes:
      - name: LAN3
        ipaddr: 172.16.2.144/28
        gateway: 172.16.2.186

net.ipv4.ip_forward:
  sysctl:
    - present
    - value: 1

## Configure inetd
update-inetd --add "echo stream tcp nowait nobody internal":
  cmd:
    - run

## Lance inetd
service inetutils-inetd start:
  cmd:
    - run

service inetutils-inetd restart:
  cmd:
    - run
