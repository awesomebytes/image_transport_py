#include "ros/ros.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <image_transport/image_transport.h>
#include "roscpp_to_rospy/roscpp_to_rospy.h"

/*
Author: Sammy Pfeiffer
*/

namespace py = pybind11;

// Expose a image_transport stuff to Python

/* Create a ImageTransport */
class ImageTransportPy{
public:
ImageTransportPy(ROScppNode node){
    it_ = new image_transport::ImageTransport(*node.nh_);
}

~ImageTransportPy() {}

image_transport::ImageTransport *it_;

};

PYBIND11_MODULE(image_transport_py, m) {
    m.doc() = "pybind11 image_transport_py";

    py::class_<ImageTransportPy>(m, "ImageTransportPy")
        .def(py::init<ROScppNode>(),
            "Create a ImageTransport plugin",
                py::arg("node"));

}