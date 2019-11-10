up-all:
	$(MAKE) VM1 VM3 VM1-6 VM2-6 VM3-6 -j

halt-all:
	$(MAKE) halt-VM1 halt-VM3 halt-VM1-6 halt-VM2-6 halt-VM3-6 -j

destroy-all:
	$(MAKE) destroy-VM1 destroy-VM3 destroy-VM1-6 destroy-VM2-6 destroy-VM3-6 -j
VM1:
	cd VMs/VM1 && vagrant up
VM2:
	cd VMs/VM2 && vagrant up
VM3:
	cd VMs/VM3 && vagrant up
VM1-6:
	cd VMs/VM1-6 && vagrant up
VM2-6:
	cd VMs/VM2-6 && vagrant up
VM3-6:
	cd VMs/VM3-6 && vagrant up

halt-VM1:
	cd VMs/VM1 && vagrant halt
halt-VM2:
	cd VMs/VM2 && vagrant halt
halt-VM3:
	cd VMs/VM3 && vagrant halt
halt-VM1-6:
	cd VMs/VM1-6 && vagrant halt
halt-VM2-6:
	cd VMs/VM2-6 && vagrant halt
halt-VM3-6:
	cd VMs/VM3-6 && vagrant halt


destroy-VM1:
	cd VMs/VM1 && vagrant destroy -f
destroy-VM2:
	cd VMs/VM2 && vagrant destroy -f
destroy-VM3:
	cd VMs/VM3 && vagrant destroy -f
destroy-VM1-6:
	cd VMs/VM1-6 && vagrant destroy -f
destroy-VM2-6:
	cd VMs/VM2-6 && vagrant destroy -f
destroy-VM3-6:
	cd VMs/VM3-6 && vagrant destroy -f
