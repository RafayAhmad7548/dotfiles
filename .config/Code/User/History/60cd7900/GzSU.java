package com.jb;

import javafx.animation.Transition;
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

    private static int noOfTabs;

    private StackPane root;
    private Scene scene;
    private static Button newTabBtn;
    
    @Override
    public void start(Stage stage){
        toggleGroup = new ToggleGroup();
        noOfTabs = 1;
        root = new StackPane();
        scene = new Scene(root);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());

        BrowserTab tab = new BrowserTab();


        root.getChildren().addAll(tab.getNodes());
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
            noOfTabs++;
            BrowserTab newTab = new BrowserTab();
            root.getChildren().addAll(newTab.getNodes());
            TranslateTransition tt = new TranslateTransition(new Duration(250), newTabBtn);
            tt.setByX(155);
            tt.play();
            // newTabBtn.setTranslateX(newTabBtn.getTranslateX() + 155);
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

    public static void setNoOfTabs(int tabs){
        noOfTabs = tabs;
    }
    public static int getNoOfTabs(){
        return noOfTabs;
    }




}