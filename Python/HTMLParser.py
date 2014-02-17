'''
enviroment : python 3.3.2
'''
from html.parser import HTMLParser

class MyHtmlParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print("start tag", tag, attrs)

    def handle_endtag(self, tag):
        print ("end tag", tag)

    def handle_startendtag(self, tag, attrs):
        print ("start end tag", tag, attrs)

    def handle_data(self, data):
        print ("data", data)

    def handle_comment(self, data):
        print ("comment", data)

    def handle_decl(self, decl):
        '''handle <!DOCTYPE ...>'''
        print ("<!", decl)

    def unknow_decl(self, data):
        '''raise an HTMLParserError when encountering unexpected error'''
        pass

    def handle_pi(self, data):
        print ("processing instruction", data)

    def handle_entityref(self, name):
        print ("entiryref", name)

    def handle_charref(self, name):
        print ("charref", name)

import urllib.request


def turnWebHtmlIntoStr(webSite):
    web = urllib.request.urlopen(webSite)
    webContent = web.read().decode("utf8")
    web.close()
    return webContent

if __name__ == '__main__':
    webSite = "http://yahoo.com.tw"
    webContent = turnWebHtmlIntoStr(webSite)

    parser = MyHtmlParser()
    #feed string into parser
    for line in webContent.splitlines():
        parser.feed(str(line))
