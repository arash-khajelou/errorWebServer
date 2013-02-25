from twisted.web import proxy, http
from twisted.internet import reactor
from twisted.python import log
from twisted.protocols import basic
import sys
log.startLogging(sys.stdout)

class InformixProtocol(basic.LineReceiver):
    def lineReceived(self, user):
        self.transport.write("Hello this is twisted web server!")
        self.transport.loseConnection()

class ProxyFactory(http.HTTPFactory):
    #protocol = proxy.Proxy
    protocol = InformixProtocol

reactor.listenTCP(8081, ProxyFactory())
reactor.run()
