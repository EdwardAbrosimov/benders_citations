# Description
This package was created for an example of creating a node with a subscriber and publisher, as well as interaction through the service. The package contains the node with a publisher who publishes Bender's quotes in the topic. In another topic, the user sends the number of the next quote. In addition, there is a service implementation. The service server receives the quote number and returns the quote text in response. There is also a node - a client of the service, which expects a quote number on the standard input and itself makes a request to the service. And a node that automatically sends a request to the service with a random quote number.
## Usage
### To run node with publishe and subscriber with params execute:
`roslaunch benders_citations citations.launch`
### To run service server execute:
`rosrun benders_citations citations_server `
### To run service client node execute:
`rosrun benders_citations citations_client `
### To run auto-citations client node execute:
`rosrun benders_citations auto_citations_client `
