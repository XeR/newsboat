/* rsspp - Copyright (C) 2008-2009 Andreas Krennmair <ak@newsbeuter.org>
 * Licensed under the MIT/X Consortium License. See file LICENSE
 * for more information.
 */

#ifndef RSSPP_INTERNAL__H
#define RSSPP_INTERNAL__H

#include <rsspp.h>
#include <tr1/memory>

#define CONTENT_URI		"http://purl.org/rss/1.0/modules/content/"
#define RDF_URI			"http://www.w3.org/1999/02/22-rdf-syntax-ns#"
#define ITUNES_URI		"http://www.itunes.com/dtds/podcast-1.0.dtd"
#define DC_URI			"http://purl.org/dc/elements/1.1/"
#define ATOM_0_3_URI	"http://purl.org/atom/ns#"
#define ATOM_1_0_URI	"http://www.w3.org/2005/Atom"
#define MEDIA_RSS_URI	"http://search.yahoo.com/mrss/"

namespace rsspp {

struct rss_parser {
		virtual void parse_feed(feed& f, xmlNode * rootNode) = 0;
		virtual ~rss_parser() { }
	protected:
		std::string get_content(xmlNode * node);
		std::string get_prop(xmlNode * node, const char * prop, const char * ns = NULL);
		std::string w3cdtf_to_rfc822(const std::string& w3cdtf);
		bool node_is(xmlNode * node, const char * name, const char * ns_uri = NULL);
};

struct rss_09x_parser : public rss_parser {
		virtual void parse_feed(feed& f, xmlNode * rootNode);
		virtual ~rss_09x_parser() { }
	private:
		item parse_item(xmlNode * itemNode);
};

struct rss_20_parser : public rss_09x_parser {
	virtual ~rss_20_parser() { }
};

struct rss_10_parser : public rss_parser {
	virtual void parse_feed(feed& f, xmlNode * rootNode);
	virtual ~rss_10_parser() { }
};


struct atom_parser : public rss_parser {
		virtual void parse_feed(feed& f, xmlNode * rootNode);
		virtual ~atom_parser() { }
	private:
		item parse_entry(xmlNode * itemNode);
};

struct rss_parser_factory {
	static std::tr1::shared_ptr<rss_parser> get_object(feed& f);
};

}

#endif
