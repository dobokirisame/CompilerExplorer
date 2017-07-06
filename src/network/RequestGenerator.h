#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H
#include <QString>

namespace compilerExplorer {
namespace network{
class Request;
class RequestGeneratorPrivate;
class RequestGenerator
{
public:
	RequestGenerator(const QString &address, const int port);
	virtual ~RequestGenerator();
	Request *createCompilerRequest();
	static Request *comilersListRequest(const QString &address, const int port);
private:
	RequestGeneratorPrivate *d;
};
}
}
#endif // REQUESTGENERATOR_H
