#ifndef COMPILERSLISTREQUESTPARSER_H
#define COMPILERSLISTREQUESTPARSER_H
#include <QByteArray>

namespace compilerExplorer {
namespace network{
class CompilersListReplyParser
{
public:
	explicit CompilersListReplyParser(const QByteArray &reply);
	static std::map<QString, QString> parse(QByteArray reply);
private:
	void parse();
private:
	QByteArray mReply;
};
}
}
#endif // COMPILERSLISTREQUESTPARSER_H
