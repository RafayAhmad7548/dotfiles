package com.jb;

import java.util.ArrayList;

import javafx.scene.Node;
import javafx.scene.layout.StackPane;

public class BrowserTab{

    private TabButton tabButton;
    private StackPane stackPane;

    private ArrayList<Node> nodes;

    public BrowserTab(){
        tabButton = new TabButton();
        stackPane = new StackPane();
        stackPane.setTranslateY(70);
        stackPane.setStyle("-fx-background-color: black;");

        nodes = new ArrayList<>();
        nodes.add(stackPane);
        nodes.add(tabButton);

    }

    public ArrayList<Node> getNodes(){
        return nodes;
    }

}
