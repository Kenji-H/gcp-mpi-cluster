gcp-mpi-cluster
=====================================================

## Terraform

### Preperations
- download your GCP sevice account key and save it as `terraform/account.json`.
- create `terraform/terraform.tfvars` and set your GCP project configuration.

```
project = "YOUR_PROJECT_NAME"
region = "YOUR_REGION_NAME"
zone = "YOUR_ZONE_NAME"
```

### Plan
```
$ terraform plan
```

### Apply
```
$ terraform apply
```

## Ansible
### Install
```
$ ansible-playbook site.yml -i hosts
```

### Compile
```
$ ansible-playbook compile.yml -i hosts
```

### Run
```
$ ansible-playbook run.yml -i hosts
```

