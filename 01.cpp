#include <iostream>
#include <fstream>

class LogCommand {
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class FileLog : public LogCommand
{
public:
	FileLog(const std::string& f_path, std::ofstream* f_str) : file_path{ f_path }, f_ostream{f_str} {}
	void print(const std::string& message) override
	{
		f_ostream->open(file_path, std::ios::app);
		if (f_ostream->is_open())
		{
			*f_ostream << message << std::endl;
		}
	}
	~FileLog() { f_ostream->close(); }

private:
	const std::string file_path;
	std::ofstream* f_ostream;
};

class ConsoleLog : public LogCommand
{
public:
	ConsoleLog(std::ostream* p_ostr) : p_ostream{ std::move(p_ostr) } {}
	void print(const std::string& message) override
	{
		*p_ostream << message << std::endl;
	}
	~ConsoleLog() {};

private:
	std::ostream* p_ostream;
};

void print(LogCommand& lc)
{
	lc.print("Hello");
}

int main()
{
	ConsoleLog cl(&std::cout);
	print(cl);
	std::ofstream ofs;
	FileLog fl("file_path", &ofs);
	print(fl);
	return 0;
}
