import networkx as nx
import matplotlib.pyplot as plt

def create_semantic_network():
    """
    Creates and visualizes a semantic network based on a set of facts.
    """

    # Step 1: Create a directed graph G.
    # This graph will store entities (nodes) and their relationships (edges).
    G = nx.DiGraph()

    # Step 2: Define all entities appearing in the news.
    ENTITIES = [
        "Election 2025",
        "John Smith",
        "Democratic Party",
        "New York",
        "Jane Miller",
        "Republican Party",
        "Debate Event",
        "News Channel"
    ]

    # Step 3: Add entities as nodes in the graph.
    # Each node represents a concept/person/place/event.
    G.add_nodes_from(ENTITIES)

    # Step 4: Define the relationships between entities.
    # The relationships are tuples of (source, target, relation_text).
    RELATIONSHIPS = [
        ("John Smith", "Election 2025", "is a candidate in"),
        ("Jane Miller", "Election 2025", "is a candidate in"),
        ("John Smith", "Democratic Party", "is a member of"),
        ("Jane Miller", "Republican Party", "is a member of"),
        ("Debate Event", "Election 2025", "is part of"),
        ("John Smith", "Debate Event", "participated in"),
        ("Jane Miller", "Debate Event", "participated in"),
        ("News Channel", "Debate Event", "reported on"),
        ("Election 2025", "New York", "is held in")
    ]

    # Step 5: Add relationships to the graph.
    # For each relationship, add a directed edge from source to target.
    # Store the relation_text as an attribute called "relation".
    for src, tgt, rel in RELATIONSHIPS:
        G.add_edge(src, tgt, relation=rel)

    # Step 6: Define a function to convert relationships to sentences.
    def generate_sentences(graph):
        """
        Generates human-readable sentences from the graph's relationships.
        """
        sentences = []
        for src, dst, data in graph.edges(data=True):
            relation_text = data.get("relation")
            sentence = f"{src} {relation_text} {dst}."
            sentences.append(sentence)
        return sentences

    # Step 7: Display relationships as human-readable news summary.
    print("News Summary based on Semantic Network:")
    summary_sentences = generate_sentences(G)
    for sentence in summary_sentences:
        print(sentence)
    print("\n" + "="*50 + "\n")

    # Step 8: Prepare to visualize the semantic network.
    plt.figure(figsize=(10, 7))

    # Calculate node positions using a spring layout.
    pos = nx.spring_layout(G, k=0.8, iterations=50)

    # Step 9: Draw the semantic network.
    # Labeled nodes, light blue color, node size 2000, bold font.
    nx.draw_networkx_nodes(G, pos, node_size=2000, node_color="#ADD8E6")
    nx.draw_networkx_labels(G, pos, font_size=10, font_weight="bold")

    # Draw arrows to indicate the direction of relationships.
    nx.draw_networkx_edges(G, pos, arrowsize=20, edge_color="gray", width=2)

    # Get and draw all edge labels (the "relation" attributes) in red text.
    edge_labels = nx.get_edge_attributes(G, 'relation')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color="red")

    # Step 10: Finalize and display the plot.
    plt.title("Semantic Network Representation of News")
    plt.show()

# Run the program
create_semantic_network()

