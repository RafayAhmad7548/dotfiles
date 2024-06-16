package com.jb;

import java.util.ArrayList;

import javafx.animation.TranslateTransition;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application{

    private static ToggleGroup toggleGroup;

    private static ArrayList<BrowserTab> tabs;

    private StackPane root;
    private Scene scene;
    private static Button newTabBtn;
    
    @Override
    public void start(Stage stage){
        toggleGroup = new ToggleGroup();
        tabs = new ArrayList<>();       
        root = new StackPane();
        scene = new Scene(root);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());

        tabs.add(new BrowserTab());


        root.getChildren().addAll(tabs.get(0).getTabButton(), tabs.get(0).getStackPane());
        initializeButton();

        stage.setScene(scene);
        stage.show();

    }

    private void initializeButton(){
        newTabBtn = new Button("");
        StackPane.setAlignment(newTabBtn, Pos.TOP_LEFT);
        newTabBtn.setId("new-tab-button");
        newTabBtn.setTranslateX(tabs.size()*150 + 7.5);
        root.getChildren().add(newTabBtn);

        newTabBtn.setOnAction(e -> {
            tabs.add(new BrowserTab());
            root.getChildren().addAll(tabs.get(tabs.size()-1).getNodes());
            TranslateTransition tt = new TranslateTransition(new Duration(250), newTabBtn);
            tt.setByX(155);
            tt.play();
        });

    }

    public static void main(String[] args){
        launch(args);
    }

    public static Button getNewTabBtn(){
        return newTabBtn;
    }
    public static ToggleGroup getToggleGroup(){
        return toggleGroup;
    }
    public static int getNoOfTabs(){
        return tabs.size();
    }
    public static ArrayList<BrowserTab> getTabs(){
        return tabs;
    }




}