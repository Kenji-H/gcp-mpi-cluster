provider "google" {
  credentials = "${file("account.json")}"
  project     = "${var.project}"
  region      = "${var.region}"
}

resource "google_compute_instance" "mpi_nodes" {
  count        = 5
  name         = "${format("mpi-%d", count.index)}"
  machine_type = "n1-standard-1"
  zone         = "${var.zone}"

  boot_disk {
    initialize_params {
      image = "centos-cloud/centos-7"
    }
  }

  network_interface {
    network = "default"
    access_config {
      // add an ephemeral IP to each instance
    }
  }
}
