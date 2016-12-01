/*!
    \file process.h
    \brief Process definition
    \author Ivan Shynkarenka
    \date 01.12.2016
    \copyright MIT License
*/

#ifndef CPPCOMMON_SYSTEM_PROCESS_H
#define CPPCOMMON_SYSTEM_PROCESS_H

#include <memory>

//! Current process Id macro
/*!
    Get the current process Id.
*/
#define __THREAD__ CppCommon::Process::CurrentProcessId()

namespace CppCommon {

//! Process abstraction
/*!
    Process contains different kinds of process manipulation functionality such as
    retrive the current process Id, execute or terminate one.

    Thread-safe.
*/
class Process
{
public:
    Process();
    Process(const Process&) = delete;
    Process(Process&&) noexcept;
    ~Process();

    Process& operator=(const Process&) = delete;
    Process& operator=(Process&&) noexcept;

    //! Get the current process Id
    /*!
        \return Current process Id
    */
    static uint64_t CurrentProcessId() noexcept;
    //! Get the parent process Id
    /*!
        \return Parent process Id
    */
    static uint64_t ParentProcessId() noexcept;

    //! Swap two instances
    void swap(Process& process) noexcept;
    friend void swap(Process& process1, Process& process2) noexcept;

private:
    class Impl;
    std::unique_ptr<Impl> _pimpl;
};

/*! \example system_process.cpp Process abstraction example */

} // namespace CppCommon

#include "process.inl"

#endif // CPPCOMMON_SYSTEM_PROCESS_H
