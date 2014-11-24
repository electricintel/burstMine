#ifndef CRYO_OPENCL_KERNEL_H
#define CRYO_OPENCL_KERNEL_H

#include <memory>
#include <CL/cl.h>

#include "OpenclError.h"

namespace cryo {
namespace opencl {

class OpenclKernel {
	private:
		std::unique_ptr<cl_kernel> m_handle;

	public:
		OpenclKernel(std::unique_ptr<cl_kernel>& p_handle);
		OpenclKernel(const OpenclKernel& p_other) = delete;
		virtual ~OpenclKernel() throw ();

		OpenclKernel& operator=(const OpenclKernel& p_other) = delete;

		inline const cl_kernel& getHandle() const;

		void setKernelArgument(unsigned int p_index, std::size_t p_size, void* p_value) throw (OpenclError);
};

}}

namespace cryo {
namespace opencl {

inline const cl_kernel& OpenclKernel::getHandle() const {
	return *m_handle;
}

}}

#endif