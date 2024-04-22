# ipcalc

a cli tool for converting between decimal and binary versions of IPv4 and IPv6 addresses
and do some operations on IP addresses, check [features](#features) for more info.

## features
**SOON**

## usage

### requirements

* make
* gcc or clang


### installation

* initialization:
```sh
make init
```

* compiling and installing:
```sh
make install
```

* unistalling:
```sh
make uninstall
```


### available options

> [!NOTE]
> the only two options that works are **-b** and **-h**

```
-b,	--bin=DEC	convert decimal to binary
-d,	--dec=BIN	convert binary to decimal
-h,	--help		print this help
```

**Notes:**
* `-b` can be used multiple times in a single command


## todo

- [ ] Makefile:
	- [ ] organize the dependancy graph
- [ ] display:
    - [ ] network address
		- [ ] implement `to_ip()` (from string to ip_addr struct)
		- [ ] finish implementing `is_net()`
		- [ ] integrate `is_net()` in the program
		- [ ] add options: `--isnet`, `--isint`
    - [ ] usable host ip range
    - [ ] broadcast address
    - [ ] total number of hosts
    - [ ] number of usable hosts
    - [ ] subnet mask (for example from */16* to *255.255.0.0*)
    - [ ] wildcard mask
    - [X] binary ip address
    - [ ] binary subnet mask
    - [ ] ip class
    - [ ] **CIDR** notation (*/24*) of the subnet mask (*255.255.255.0*)
    - [ ] ip type: **public** or **private**
    - [ ] short notation, ex: `192.168.1.1/24`
    - [ ] all possible addresses for the ip address
    - [ ] table of the number of hosts per subnet
- [ ] use the [belformat](https://github.com/Artiom-Astashonak/belformat) library
- [ ] add some examples
- [X] make an `ip` struct
- [X] use `getopt_long` or `getopt_long_only` instead of `getopt`
- [ ] handle errors like a pro
- [ ] think about making the while loop in `main` as the following steps:
	1. **check** for option
	2. **handle** option
	3. **log** errors
