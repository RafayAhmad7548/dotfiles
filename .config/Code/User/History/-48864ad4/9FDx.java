package com.jb;

import java.util.ArrayList;

import javafx.scene.Node;
import javafx.scene.layout.StackPane;

public class BrowserTab{

    private TabButton tabButton;
    private StackPane stackPane;

    private ArrayList<? extends Node> nodes;

    public BrowserTab(){
        tabButton = new TabButton();
        stackPane = new StackPane();
        stackPane.setTranslateY(70);
        stackPane.setStyle("-fx-background-color: black;");
    }
}
