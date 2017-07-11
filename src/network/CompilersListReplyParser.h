#ifndef COMPILERSLISTREQUESTPARSER_H
#define COMPILERSLISTREQUESTPARSER_H
#include <QByteArray>
#include <QString>
#include <map>

namespace compilerExplorer {
namespace network{
class CompilersListReplyParser
{
public:
	explicit CompilersListReplyParser(const QByteArray &reply);
	static std::map<QString, QString> parse(QByteArray reply);
private:
	std::map<QString, QString> parseReply();
private:
	QByteArray mReply;
};
}
}
#endif // COMPILERSLISTREQUESTPARSER_H
