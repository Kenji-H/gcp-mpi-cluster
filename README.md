gcp-mpi-cluster
=====================================================

### Install
```
$ ansible-playbook site.yml -i hosts --private-key=~/.ssh/google_compute_engine
```

### Compile
```
$ ansible-playbook compile.yml -i hosts --private-key=~/.ssh/google_compute_engine
```

### Run
```
$ ansible-playbook run.yml -i hosts --private-key=~/.ssh/google_compute_engine
```

