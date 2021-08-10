# WebServ
In this project is I  write your HTTP server. HTTP is one of the most used protocols on the internet. Knowing its arcane will be useful, even if you won’t be working on a website.

# what you need to know !

<a href="https://github.com/Hamzaelkhatri/WebServe">read this Readme 
</a>


Extra : 
</br>
<a href="https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview">HTTP</a><br>
<a href="https://www.geeksforgeeks.org/socket-programming-cc/">Socket in cpp </a><br>
<a href="https://searchapparchitecture.techtarget.com/definition/RESTful-API">Details about REST API</a>



# Notes:
    Initially HTTP client or Web Browser sends a HTTP request to the HTTP server.
    Server Process The request received  and sends HTTP response to the HTPP client.
    REST API :  is an architectural style for an  API that uses HTTP requests to access and use data.

# Nginx Block Configurations
    Nginx logically divides the configurations meant to serve different content into blocks, which live in a hierarchical   structure. Each time a client request is made, Nginx begins a process of determining which configuration blocks should beused to handle the request. This decision process is what we will be discussing in this guide.
    The main blocks that we will be discussing are the server block and the location block:
        A server block is a subset of Nginx’s configuration that defines a virtual server used to handle requests of a defined type. Administrators often configure multiple server blocks and decide which block should handle which connection based on the requested domain name, port, and IP address.
        A location block lives within a server block and is used to define how Nginx should handle requests for different   resources and URIs for the parent server. The URI space can be subdivided in whatever way the administrator likes using these blocks. It is an extremely flexible model.

# How Nginx Decides Which Server Block Will Handle a Request
    Since Nginx allows the administrator to define multiple server blocks that function as separate virtual web server  instances, it needs a procedure for determining which of these server blocks will be used to satisfy a request.
    It does this through a defined system of checks that are used to find the best possible match. The main server block    directives that Nginx is concerned with during this process are the listen directive, and the server_name directive.


