/*
	Burst mine
	Distributed graphical plotter and miner for Burst.
	Author: Cryo
	Bitcoin: 138gMBhCrNkbaiTCmUhP9HLU9xwn5QKZgD
	Burst: BURST-YA29-QCEW-QXC3-BKXDL
*/

#ifndef CRYO_BURST_MINE_OPENCL_CONTEXT_OPENCL_H
#define CRYO_BURST_MINE_OPENCL_CONTEXT_OPENCL_H

#include <memory>
#include <vector>
#include <exception>
#include <CL/CL.h>

#include "../../opencl/OpenclPlatform.h"
#include "../../opencl/OpenclDevice.h"
#include "../../opencl/OpenclContext.h"
#include "../../opencl/OpenclCommandQueue.h"
#include "../../opencl/OpenclBuffer.h"
#include "../../opencl/OpenclProgram.h"
#include "../../opencl/OpenclKernel.h"
#include "../../opencl/OpenclError.h"
#include "OpenclDeviceConfig.h"

namespace cryo {
namespace burstMine {
namespace opencl {

class ContextOpencl {
	private:
		std::shared_ptr<OpenclDeviceConfig> m_config;
		std::unique_ptr<unsigned char[]> m_bufferCpu;
		std::shared_ptr<cryo::opencl::OpenclPlatform> m_platform;
		std::shared_ptr<cryo::opencl::OpenclDevice> m_device;
		std::shared_ptr<cryo::opencl::OpenclContext> m_context;
		std::shared_ptr<cryo::opencl::OpenclCommandQueue> m_commandQueue;
		std::shared_ptr<cryo::opencl::OpenclBuffer> m_bufferDevice;
		std::shared_ptr<cryo::opencl::OpenclProgram> m_program;
		std::vector<std::shared_ptr<cryo::opencl::OpenclKernel>> m_kernels;

	public:
		ContextOpencl(const std::shared_ptr<OpenclDeviceConfig>& p_config) throw (std::exception, cryo::opencl::OpenclError);
		ContextOpencl(const ContextOpencl& p_other) = delete;
		virtual ~ContextOpencl();

		ContextOpencl& operator=(const ContextOpencl& p_other) = delete;

		void computePlots(unsigned long long p_address, unsigned long long p_offset, unsigned int p_workSize) throw (std::exception, cryo::opencl::OpenclError);
		void bufferPlots(unsigned int p_workSize) throw (cryo::opencl::OpenclError);
};

}}}

#endif
