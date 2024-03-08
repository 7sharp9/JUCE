/*
  ==============================================================================

   This file is part of the JUCE 8 technical preview.
   Copyright (c) Raw Material Software Limited

   You may use this code under the terms of the GPL v3
   (see www.gnu.org/licenses).

   For the technical preview this file cannot be licensed commercially.

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

namespace juce
{

void ChildProcessManager::checkProcesses()
{
    for (auto it = processes.begin(); it != processes.end();)
    {
        auto processPtr = *it;

        if (! processPtr->isRunning())
        {
            listeners.call (processPtr.get());
            it = processes.erase (it);
        }
        else
        {
            ++it;
        }
    }

    if (processes.empty())
        timer.stopTimer();
}

JUCE_IMPLEMENT_SINGLETON (ChildProcessManager)

} // namespace juce
