#include "CompilersListReplyParser.h"

namespace compilerExplorer {
namespace network{

CompilersListReplyParser::CompilersListReplyParser(const QByteArray &reply) {
	CompilersListReplyParser parser(reply);
	parser.parse();
}

std::map<QString, QString> CompilersListReplyParser::parse(QByteArray reply) {
	Q_UNUSED(reply);
	return {};
}

void CompilersListReplyParser::parse() {

}


}
}
