#include "process.h"

Process::Process() {}

void Process::AddBath(Bath *bath)
{
    m_baths.push_back(bath);
}

void Process::SetName(const QString &name)
{
    m_name = name;
}
