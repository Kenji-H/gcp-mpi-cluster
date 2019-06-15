output "instance_ips" {
  value = "${google_compute_instance.mpi_nodes.*.network_interface.0.access_config.0.nat_ip}"
}
