/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_tools.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:46:25 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/09/16 12:16:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.hpp"

int Server::_Accept_client(int sock)
{
    socklen_t client_len = sizeof(client);
    int addrlen = sizeof(client);
    csock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&addrlen);
    if (csock != -1)
    {
        fcntl(csock, F_SETFL, O_NONBLOCK);
        FD_SET(csock, &masterfds);
        FD_SET(csock, &writefds);
        if (csock > maxfd)
            maxfd = csock;

        std::cout << csock << "\t  =  New connection" << std::endl;
    }
    else
      throw(AcceptFailed());
    _clients.insert(std::pair<int, std::string>(csock, ""));
    return (csock);
}

int Server::_Get_request(int sock)
{
    char buf[BUFFER_SIZE + 1];
    int n;
    int i = 0;
    bzero(buf, BUFFER_SIZE + 1);
    if ((n = recv(sock, buf, BUFFER_SIZE, 0)) > 0)
    {
        if (i == 0)
        {
            std::strcpy(this->request, buf);
            i++;
        }
        else
            std::strcat(this->request, buf);
    }
    return (n);
}
bool Server::checkRequest(std::string &req)
{
	if (!(req.find("\r\n\r\n") == std::string::npos))
	{
		std::string headers = req.substr(0, req.find("\r\n\r\n") + 4);
		if (headers.find("Content-Length") != std::string::npos)
		{
			size_t length = std::atoi(headers.substr(headers.find("Content-Length: ")).c_str() + 16);
			std::string body = req.substr(req.find("\r\n\r\n") + 4);
			if (body.length() < length)
				return false;
		}
		return true;
	}
	return false;
}

void    Server::witch_server(std::map<int,std::string> str ,Parsing *pars)
{
    std::multimap <int, std::multimap<std::string, std::string> > _loc_map;
    // _loc_map = p->Getloc_map();
    
}

// char * removeHTTPHeader(char *buffer, int &bodySize)
//  {
//     char *t = strstr(buffer, "\r\n\r\n");
//     t = t + 4;

//     for (char* it = buffer; it != t; ++it) 
//         ++bodySize;

//     return t;
// }


int Server::check_index(std::string str)
{
    int ret = open(str.c_str(), O_RDONLY);
    if (ret == -1)
        return (0);
    close(ret);
    return (1);
}

int Server::check_dir(std::string dir, std::string str)
{
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dir.c_str());
    if (dirp == NULL)
        return (0);
    int i = 0;
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_name[0] == '.')
            continue;
        if (dp->d_type == DT_DIR)
        {
            i++;
            std::string tmp = dir + "" + dp->d_name;
            // std::cout << tmp << "  " << str << "\n";
            if (tmp.find(str) != std::string::npos)
            {
                if (check_index(tmp + "/index.html"))
                    return (1);
                else
                    return (0);
            }
        }
        else if (dp->d_type == DT_REG && str.find(".") != std::string::npos)
        {
            std::string tmp = dir + "" + dp->d_name;
            // std::cout << tmp << " || " << str << "\n";
            if (tmp.find(str) != std::string::npos)
                return (2);
        }
    }
    closedir(dirp);
    if (str.find(".") == std::string::npos)
    {
        dirp = opendir(str.c_str());
        if (dirp == NULL)
            return (0);
        closedir(dirp);
    }
    else
    {
        int ret = open(str.c_str(), O_RDONLY);
        if (ret == -1)
            return (0);
        close(ret);
    }
    return (2);
}

// std::string Server::getBody(std::string path)
// {
//     std::string body;
//     std::ifstream file(path);
//     if (file.is_open())
//     {
//         std::string line;
//         while (getline(file, line))
//         {
//             body += line;
//             body += "\n";
//         }
//         file.close();
//     }
//     return body;
// }

// void Server::SaveFile(std::string path, std::string body,int size)
// {
//     std::ofstream file(path, std::ios::out | std::ios::binary);
//     if (file.is_open())
//     {
//         file.write(body.c_str(), size);
//         file.close();
//     }
// }


