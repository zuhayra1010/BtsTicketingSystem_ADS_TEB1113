# BtsTicketingSystem_ADS_TEB1113

When a popular K-pop group such as BTS announces a concert, ticket sales open at one fixed time, and a huge number of fans try to buy a limited number of seats within the same few minutes. For this project, we simulate a scenario where 10,000 users attempt to purchase tickets from a pool of 5,000 available seats within the first minute after sales open. This kind of sudden demand spike is common for high-profile ticket releases and is known to cause two major issues on real ticketing platforms:  

• Long waiting time - because thousands of users send requests to the server in the same short window, the system has to process all of them together. Users end up waiting on the page for a long time, often without knowing how long the wait will be or whether their request is even being processed. 

 • System crash - when the server tries to handle all 10,000 requests at the same moment with no control over the order or pace of incoming traffic, it runs out of processing capacity and memory, causing the system to crash. Users lose their connection and may lose their place in line entirely, even if they had been waiting since before the sale started.
