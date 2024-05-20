import matplotlib.pyplot as plt
import networkx as nx
import argparse

# Function to read the graph from a file
def read_graph_from_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        
    # First line contains the number of nodes and edges
    first_line = lines[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    edges = []
    for line in lines[1:]:
        u, v = map(int, line.strip().split())
        edges.append((u, v))
    
    return N, M, edges

# Function to create and draw the graph
def draw_graph(file_path):
    N, M, edges = read_graph_from_file(file_path)
    
    # Initialize the directed graph
    G = nx.DiGraph()
    
    # Add edges to the graph
    G.add_edges_from(edges)
    
    # Draw the graph
    plt.figure(figsize=(12, 12))
    nx.draw(G, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_weight='bold', edge_color='gray', arrows=True)
    plt.title("Directed Graph Visualization")
    plt.show()

# Main function to handle argument parsing
def main():
    parser = argparse.ArgumentParser(description="Draw a directed graph from a file.")
    parser.add_argument("file_path", help="Path to the file containing graph data.")
    args = parser.parse_args()
    
    draw_graph(args.file_path)

if __name__ == "__main__":
    main()
