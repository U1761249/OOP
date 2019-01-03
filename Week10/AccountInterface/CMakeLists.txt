cmake_minimum_required(VERSION 3.12)
project(AccountInterface)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(AccountInterface)
include_directories(AccountInterface/CRLForm)
include_directories(AccountInterface/Debug)

add_executable(AccountInterface
        AccountInterface/CRLForm/Account.cpp
        AccountInterface/CRLForm/Account.h
        AccountInterface/CRLForm/BankInterface.h
        AccountInterface/CRLForm/Controller.cpp
        AccountInterface/CRLForm/Controller.h
        AccountInterface/CRLForm/MyForm.cpp
        AccountInterface/CRLForm/stdafx.cpp
        AccountInterface/CRLForm/stdafx.h
        AccountInterface/Debug/CRLForm.tlog/cl.command.1.tlog
        AccountInterface/Debug/CRLForm.tlog/cl.read.1.tlog
        AccountInterface/Debug/CRLForm.tlog/cl.write.1.tlog
        AccountInterface/Debug/CRLForm.tlog/CRLForm.lastbuildstate
        AccountInterface/Debug/CRLForm.tlog/link.command.1.tlog
        AccountInterface/Debug/CRLForm.tlog/link.read.1.tlog
        AccountInterface/Debug/CRLForm.tlog/link.write.1.tlog
        AccountInterface/Debug/CRLForm.tlog/metagen.read.1.tlog
        AccountInterface/Debug/CRLForm.tlog/metagen.write.1.tlog
        AccountInterface/Debug/CRLForm.tlog/RSAENH.DLL.bi
        AccountInterface/Debug/CRLForm.tlog/TZRES.DLL.bi
        AccountInterface/Debug/FormExample.tlog/cl.command.1.tlog
        AccountInterface/Debug/FormExample.tlog/CL.read.1.tlog
        AccountInterface/Debug/FormExample.tlog/CL.write.1.tlog
        AccountInterface/Debug/FormExample.tlog/FormExample.lastbuildstate
        AccountInterface/Debug/FormExample.tlog/FormExample.write.1u.tlog
        AccountInterface/Debug/FormExample.tlog/link.command.1.tlog
        AccountInterface/Debug/FormExample.tlog/link.read.1.tlog
        AccountInterface/Debug/FormExample.tlog/link.write.1.tlog
        AccountInterface/Debug/FormExample.tlog/metagen.read.1.tlog
        AccountInterface/Debug/FormExample.tlog/metagen.write.1.tlog
        AccountInterface/Debug/FormExample.tlog/RSAENH.DLL.bi
        AccountInterface/Debug/FormExample.tlog/TZRES.DLL.bi
        AccountInterface/Debug/.NETFramework,Version=v4.5.AssemblyAttributes.obj
        AccountInterface/Debug/CRLForm.exe
        AccountInterface/Debug/CRLForm.exe.metagen
        AccountInterface/Debug/CRLForm.log
        AccountInterface/Debug/CRLForm.MyForm.resources
        AccountInterface/Debug/CRLForm.pdb
        AccountInterface/Debug/CRLForm.vcxproj.GenerateResource.Cache
        AccountInterface/Debug/CRLForm.vcxprojResolveAssemblyReference.cache
        AccountInterface/Debug/FormExample.exe
        AccountInterface/Debug/FormExample.exe.metagen
        AccountInterface/Debug/FormExample.pdb
        AccountInterface/Debug/MyForm.obj
        AccountInterface/Debug/vc120.pdb
        AccountInterface/FormExample.sln
        AccountInterface/FormExample.VC.db)
