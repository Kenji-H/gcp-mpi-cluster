GCP MPI Cluster
=====================================================

Need a distributed computing cluster?

This tool automates the creation of the [MPI] (https://en.wikipedia.org/wiki/Message_Passing_Interface) computing environment.  
All you need is write several lines of settings and run a command. 
That's it! Very simple.

## Prerequisites
Install the following tools.

- [Ansible] (https://www.ansible.com/)
- [Terraform] (https://www.terraform.io/)
- [jq] (https://stedolan.github.io/jq/)

## Create cluster

#### setup
- download your GCP sevice account key and save it as `terraform/account.json`.
- create `terraform/terraform.tfvars` and set your GCP project configuration.

```
project = "YOUR_PROJECT_NAME"
region = "YOUR_REGION_NAME"
zone = "YOUR_ZONE_NAME"
```

#### launch cluster
The following command will launch instances and set up the MPI enviroment.

```
$ ./create_cluster
```

## Run MPI program on cluster
Please save your program in `app` directory following the existing directory structure.

```
$ cd app
$ tree
.
├── divisor
│   └── main.cpp
└── hello
    └── main.cpp
```  

The below example assumes that you want to run `hello/main.cpp` on the cluster.

#### compile the program
The following command will send source code to nodes in cluster and compile the code remotely.

```
$ ./compile hello
```

#### execute the program
The following command will execute the program on the cluster.

```
$ ./run hello
```

## Destroy cluster
After playing with the cluster, please destroy the cluster to save money. You can create a cluster from scrach using the `create_cluster` command when necessary.

```
$ ./destroy_cluster
```

## Disclaimer
- This project is inteded for indivisual use case, not for bussiness use case.
- We are not responsible for any errors or problems, or results obtained from the use of this project.