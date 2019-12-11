<?php

namespace App\Http\Controllers;

use App\Models\Sensor;
use Illuminate\Http\Request;

class SensorController extends Controller
{

    public function index()
    {
        $valores = Sensor::all();
        return view('welcome',compact('valores'));
    }

    public function create()
    {
        //
    }

    public function store(Request $request)
    {
        $dados = collect(json_decode($request->getContent()));
        Sensor::create($dados->all()); //Salvando os dados do sensor

        return ('Ok');
    }

    public function show()
    {
        $valores = Sensor::all();
        return response()->json($valores->toArray());


    }

    public function edit($id)
    {
        //
    }

    public function update(Request $request, $id)
    {
        //
    }

    public function destroy($id)
    {
        //
    }
}
