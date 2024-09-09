import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'dart:io';

void main(){
  runApp(const MyApp());
  Directory dir = Directory('/');
  var list = dir.listSync();
  list.forEach(print);
}

class MyApp extends StatelessWidget{
  const MyApp({super.key});
  
  @override
  Widget build(BuildContext context){
    return ChangeNotifierProvider(
      create: (context) => MyAppState(),
      child: MaterialApp(
        title: 'First App',
        theme: ThemeData(
          useMaterial3: true,
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.green)
        ),
        home: const MyHomePage(),
      ),
    );
  }
}

class MyAppState extends ChangeNotifier{
  var counter = 0;

  void increment(){
    counter++;
    notifyListeners();
  }
}

class MyHomePage extends StatefulWidget{
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context){
    var appState = context.watch<MyAppState>();
    var sCount = appState.counter.toString();

    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('count: $sCount'),
            ElevatedButton(
              onPressed: () => appState.increment(),
              child: const Text('Increment')),
          ],
        ),
      )
    );
  }
}