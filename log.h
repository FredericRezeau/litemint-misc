// Copyright (c) 2021 Frederic 경진 Rezeau.

#ifndef LOG_H
#define LOG_H

#include<fstream>

#include "common.h"

namespace litemint
{
    class Log
    {
        DECLARE_NO_COPY(Log)
    public:
        enum class Severity : uint8_t { None, Info, Debug };
        static Severity severity;

        explicit Log(const std::string& filename, Severity severity = Severity::None)
            : m_file(filename, std::ios_base::app)
            , m_severity(severity)
        {
        }

        virtual ~Log()
        {
            m_file.close();
        }

        template<typename T>
        Log& operator << (const T& value)
        {
            if (severity >= m_severity && m_file.good()) {
                m_file << value;
            }
            return *this;
        }

        // std::endl.
        typedef std::basic_ostream<char, std::char_traits<char> > CoutType;
        typedef CoutType& (*StandardEndLine)(CoutType&);
        Log& operator << (StandardEndLine manip)
        {
            if (severity >= m_severity && m_file.good()) {
                manip(m_file);
            }
            return *this;
        }

    private:
        std::ofstream m_file;
        Severity m_severity;
    };

    Log::Severity Log::severity = Log::Severity::None;
};

#endif // LOG_H
