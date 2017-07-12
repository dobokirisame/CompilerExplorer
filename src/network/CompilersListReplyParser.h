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
	QByteArray reply() const;
	void setReply(const QByteArray &reply);
private:
	std::map<QString, QString> parseReply();
	QString removeSpacesAtEnd(const QString &text) const;
private:
	QByteArray mReply;
};
}
}
#endif // COMPILERSLISTREQUESTPARSER_H
