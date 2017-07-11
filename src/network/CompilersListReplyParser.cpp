#include "CompilersListReplyParser.h"

namespace compilerExplorer {
namespace network{

CompilersListReplyParser::CompilersListReplyParser(const QByteArray &reply)
    : mReply(reply){

}

std::map<QString, QString> CompilersListReplyParser::parse(QByteArray reply) {
	CompilersListReplyParser parser(reply);
	return parser.parseReply();
}

std::map<QString, QString> CompilersListReplyParser::parseReply() {
	return {};
}


}
}
