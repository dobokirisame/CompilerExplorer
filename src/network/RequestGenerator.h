#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H
#include <QString>
#include <memory>

class QSettings;

namespace compilerExplorer {
namespace network{
class Request;
class RequestGeneratorPrivate;
class RequestGenerator
{
public:
	RequestGenerator();
	RequestGenerator(const QString &address, const int port);
	virtual ~RequestGenerator();
	Request *createCompilerRequest();
	void setAddress(const QString &address);
	void setPort(const int port);
	void setCompilerLocation(const QString &location);
	void setCompilerOptions(const QString &options);
	void setSourceCode(const QString &code);
	void setFilters(const QStringList &filters);
	void setSetting(const QSettings &settings);
	static Request *comilersListRequest(const QString &address, const int port);
private:
	std::unique_ptr<RequestGeneratorPrivate> d;
};
}
}
#endif // REQUESTGENERATOR_H
