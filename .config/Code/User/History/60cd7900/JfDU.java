package com.jb;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application{

    private static int noOfTabs;

    private StackPane root;
    private Scene scene;
    private static Button newTabBtn;
    
    @Override
    public void start(Stage stage){
        noOfTabs = 1;
        root = new StackPane();
        scene = new Scene(root);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());

        BrowserTab tab = new BrowserTab();
        root.getChildren().add(tab);
        // tabPane = new TabPane();

        // root.getChildren().add(tabPane);
        
        // BrowserTab1 tab = new BrowserTab1();
        // tab.getWebEngine().load("https://www.google.com");
        // tabPane.getTabs().add(tab);
        initializeButton();

        stage.setScene(scene);
        stage.show();

    }

    private void initializeButton(){
        newTabBtn = new Button("");
        StackPane.setAlignment(newTabBtn, Pos.TOP_LEFT);
        newTabBtn.setId("new-tab-button");
        newTabBtn.setTranslateX(noOfTabs*150 + 7.5);
        root.getChildren().add(newTabBtn);

        newTabBtn.setOnAction(e -> {
            root.getChildren().add(new BrowserTab());
            noOfTabs++;
        });

    }

    public static void main(String[] args){
        launch(args);
    }

    public static Button getNewTabBtn(){
        return newTabBtn;
    }

    public static int getNoOfTabs(){
        return noOfTabs;
    }




}