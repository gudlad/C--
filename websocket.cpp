#include <websocketpp/client.hpp>

using namespace websocketpp;

int main()
{
    // Create a WebSocket client object.
    client c;

    // Connect the WebSocket client object to the WebSocket server.
    c.connect("ws://localhost:8080");

    // Send a message on the WebSocket connection.
    c.send("Hello, world!");

    // Receive a message on the WebSocket connection.
    std::string message = c.receive();

    // Close the WebSocket connection.
    c.close();

    return 0;
}